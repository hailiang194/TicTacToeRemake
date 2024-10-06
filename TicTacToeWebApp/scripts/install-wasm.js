import * as fs from 'fs'
import * as process from 'process'
import * as path from 'path'

const WASM_PATH = "../build/out"
const NODE_WASM_PATH = "./src/wasm"
const PUBLIC_PATH = "./public"

fs.access(WASM_PATH, fs.constants.F_OK, (error) => {
    if(error) {
        console.error(`${WASM_PATH} does not exist`)
        console.error(`Please, try to WASM`)
        return
    }


    fs.copyFile(path.join(WASM_PATH, 'TicTacToe.wasm'), path.join(NODE_WASM_PATH, "TicTacToe.wasm"), (error) => {
        if(error) {
            console.error(`Error found: ${error}`)
        }
    })  

    fs.copyFile(path.join(WASM_PATH, 'TicTacToe.js'), path.join(NODE_WASM_PATH, "TicTacToe.js"), (error) => {
        if(error) {
            console.error(`Error found: ${error}`)
        }
    }) 
    
    fs.copyFile(path.join(WASM_PATH, 'TicTacToe.data'), path.join(PUBLIC_PATH, "TicTacToe.data"), (error) => {
        if(error) {
            console.error(`Error found: ${error}`)
        }
    }) 
})