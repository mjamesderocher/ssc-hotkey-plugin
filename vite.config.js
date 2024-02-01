import { defineConfig } from 'vite'
import react from '@vitejs/plugin-react'
import externalize from 'vite-plugin-externalize-dependencies'

// https://vitejs.dev/config/
export default defineConfig({
  plugins: [
    react(),
    externalize({
      externals: [/^socket:.*/]
    })
  ],
  build: {
    rollupOptions: {
      external: [/^socket:.*/]
    }
  }
})
