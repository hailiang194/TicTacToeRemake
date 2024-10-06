<script setup lang="ts">
  import overlay from './components/overlay.vue';
  import { useTemplateRef, onMounted } from 'vue'
  import * as initModule from './wasm/TicTacToe'
  import { Module } from './wasm/Module';

  const canvasElement = useTemplateRef('canvas')

  var module = new Module()
  module.statusRef.value = "Downloading..."

  onMounted(() => {
    module.canvas = canvasElement.value
    module.canvas?.addEventListener('webglcontextlost', (e: Event) => {
      alert("WebGL context lost. You will need to reload the page."), e.preventDefault() 
    }, false)
    module.canvas?.addEventListener('contextmenu', (e: Event) => {
      e.preventDefault()
    })
    initModule.default(module)
  })

  window.onerror = () => {
    module.setStatus('Exception thrown, see JavaScript console')
    module.loadPercentRef.value = 0.0
    module.setStatus = (text: string) => {
      if (text) 
        module.printErr('[post-exception status] ' + text); 
    }
  }
</script>

<template>
  <overlay v-if="module.loadPercentRef.value < 100" :status="module.statusRef.value" :percentage="module.loadPercentRef.value" />
  <div class="w-screen h-screen bg-slate-950 emscripten_border grid place-items-center">
    <canvas class="emscripten w-full" id="canvas" ref="canvas" tabindex="-1">
    </canvas>
  </div>
</template>

<style scoped>

</style>
