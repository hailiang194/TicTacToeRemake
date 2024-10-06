<script setup lang="ts">
    const props = defineProps({
        log: {type: String, required: true}
    })
</script>
<template>
    <div class="fixed bottom-0 right-0 bg-white">
        <div>
            <textarea rows="8" class="w-[50vw]">
                {{ props.log }}
            </textarea>
        </div>
        <div class="">
            See printed log
        </div>
    </div>
</template>