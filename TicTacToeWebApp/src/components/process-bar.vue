<script setup lang="ts">
    const props = defineProps({
        percentage: {type: Number, required: true}
    })
</script>
<template>
    <div>
        <div class="w-96 h-5 border-2 border-gray-400 rounded-lg overflow-hidden bg-gray-950">
            <div :class="`h-full w-[${Math.max(props.percentage, 0.1)}%] bg-white`"></div>
        </div>
    </div>
</template>