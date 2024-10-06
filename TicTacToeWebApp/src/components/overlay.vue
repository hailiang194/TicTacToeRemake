<script setup lang="ts">
    import processBar from './process-bar.vue';
    const props = defineProps({
        status: {type: String, required: true},
        percentage: {type: Number, required: true}
    })

</script>
<template>
    <div class="fixed w-full h-full top-0 left-0 right-0 bottom-0 z-50">
        <div class="w-full h-full">
            <div class="w-full h-full grid place-items-center bg-slate-700">
                <div>
                    <p class="text-center text-cyan-50">{{ props.status }}</p>
                    <processBar :percentage="props.percentage"></processBar>
                </div>
            </div>
        </div>
    </div>
</template>