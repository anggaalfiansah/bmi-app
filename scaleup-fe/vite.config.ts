import { defineConfig } from "vite";
import react from "@vitejs/plugin-react-swc";
import { chunkSplitPlugin } from "vite-plugin-chunk-split";
import { ViteImageOptimizer } from "vite-plugin-image-optimizer";

// https://vite.dev/config/
export default defineConfig({
  plugins: [
    react(),
    chunkSplitPlugin({
      strategy: "unbundle",
      customSplitting: {
        vendor: [/node_modules/],
        assets: [/src\/assets/],
        components: [/src\/components/],
        app: [/src/],
      },
    }),
    ViteImageOptimizer(),
  ],
});
