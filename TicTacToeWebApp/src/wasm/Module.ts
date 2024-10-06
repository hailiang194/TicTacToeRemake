export class Module {
    public preRun: { (): void; }[] = []
    public postRun: { (): void; }[] = []
    public totalDependencies: number = 0
    public canvas: HTMLElement | null = null
    public output: HTMLElement | null = null
    public process: HTMLElement | null = null


    private last: {
        time: number,
        text: string
    } | null = null

    public print(t: string): void {
        console.log(t)
    }

    public setStatus(e: string): void {
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
                (this.process as HTMLProgressElement).value = 100 * parseInt(t[2]);
                (this.process as HTMLProgressElement).max = 100 * parseInt(t[4]);
                (this.process as HTMLProgressElement).hidden = false;
            } else {
                (this.process as HTMLProgressElement).value = 100;
                (this.process as HTMLProgressElement).max = 100;
                (this.process as HTMLProgressElement).hidden = true;
            }
        }
    }

    monitorRunDependencies(e: number): void {
        this.totalDependencies = Math.max(this.totalDependencies, e)
        this.setStatus(e ? `Prepare...(${this.totalDependencies - e}/${this.totalDependencies})` : "All downloads complete.");
    }
}