<script setup lang="ts">
  import { useTemplateRef, onMounted } from 'vue'
  import * as initModule from './wasm/TicTacToe'
  import { Module } from './wasm/Module';

  const progressElement = useTemplateRef('progress')
  const canvasElement = useTemplateRef('canvas')

  onMounted(() => {
    var module = new Module()
    module.canvas = canvasElement.value
    module.process = progressElement.value
    module.canvas?.addEventListener('webglcontextlost', (e: Event) => {
      alert("WebGL context lost. You will need to reload the page."), e.preventDefault() 
    }, false)
    module.canvas?.addEventListener('contextmenu', (e: Event) => {
      e.preventDefault()
    })
    initModule.default(module)
  })
</script>

<template>
   <div class="emscripten">
    <progress hidden ref="progress" max="100" value="0"></progress>
  </div>
  <div class=emscripten_border>
    <canvas class="emscripten" id="canvas" ref="canvas" tabindex="-1">
    </canvas>
  </div>
</template>

<style scoped>

</style>
