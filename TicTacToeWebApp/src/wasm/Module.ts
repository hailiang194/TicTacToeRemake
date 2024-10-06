import { ref, Ref } from "vue";

export class Module {
    public arguments: string[] = []
    public preRun: { (): void; }[] = []
    public postRun: { (): void; }[] = []
    public totalDependencies: number = 0
    public statusRef: Ref<string> = ref<string>("")
    public loadPercentRef: Ref<number> = ref<number>(0.0)
    public canvas: HTMLElement | null = null


    private last: {
        time: number,
        text: string
    } | null = null

    public print(t: string): void {
        console.log(t)
    }

    public printErr(text: string) {
        console.error(text);
    }

    public setStatus(e: string): void {
        this.statusRef.value = e
        if (!this.last) {
            this.last = {
                time: Date.now(),
                text: ""
            }
        }

        if (e !== this.last.text) {
            var t = e.match(/([^(]+)\((\d+(\.\d+)?)\/(\d+)\)/)
            var n = Date.now()

            if (t && n - this.last.time < 30) {
                this.last.text = e;
                this.last.time = n;
            }

            if(t) {
                this.loadPercentRef.value = (100 * parseInt(t[2]) * 100) / 100 * parseInt(t[4])
            } else {
                this.loadPercentRef.value = 100.0
            }
        }
    }

    public monitorRunDependencies(e: number): void {
        this.totalDependencies = Math.max(this.totalDependencies, e)
        this.setStatus(e != 0 ? `Prepare...(${this.totalDependencies - e}/${this.totalDependencies})` : "All downloads complete.");
    }
}