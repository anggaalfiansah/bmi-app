import { StrictMode } from "react";
import { createRoot } from "react-dom/client";
import "@fontsource/lobster/400.css";
import { Provider } from "./components/ui/provider";
import App from "./App.tsx";

createRoot(document.getElementById("root")!).render(
  <StrictMode>
    <Provider>
      <App />
    </Provider>
  </StrictMode>
);
