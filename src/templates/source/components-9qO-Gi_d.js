import{r as i,j as o,g as m,h as u,i as D,k as g,z as k,L as p,l as T,J as I,m as b,n as B,o as M,P as w,D as x,p as F,q as P,s as $,t as y,u as v,v as q,w as S,x as L,R as E,y as z,A as H,E as N,G as O,K as A,M as U,N as W,O as X,Q as G,T as J,U as K,V as Q,W as V,X as Y,Y as Z,Z as _}from"./vendor-Bk7EVBWR.js";function oo(a){return o.jsx(I,{attribute:"class",disableTransitionOnChange:!0,...a})}function C(){const{resolvedTheme:a,setTheme:e}=k();return{colorMode:a,setColorMode:e,toggleColorMode:()=>{e(a==="dark"?"light":"dark")}}}function eo(){const{colorMode:a}=C();return a==="dark"?o.jsx(p,{}):o.jsx(T,{})}i.forwardRef(function(e,r){const{toggleColorMode:t}=C();return o.jsx(m,{fallback:o.jsx(D,{boxSize:"8"}),children:o.jsx(u,{onClick:t,variant:"ghost","aria-label":"Toggle color mode",size:"sm",ref:r,...e,css:{_icon:{width:"5",height:"5"}},children:o.jsx(eo,{})})})});i.forwardRef(function(e,r){return o.jsx(g,{color:"fg",display:"contents",className:"chakra-theme light",colorPalette:"gray",colorScheme:"light",ref:r,...e})});i.forwardRef(function(e,r){return o.jsx(g,{color:"fg",display:"contents",className:"chakra-theme dark",colorPalette:"gray",colorScheme:"dark",ref:r,...e})});function to(a){return o.jsx(b,{value:B,children:o.jsx(oo,{...a})})}const ro=i.forwardRef(function(e,r){return o.jsx(u,{variant:"ghost","aria-label":"Close",ref:r,...e,children:e.children??o.jsx(M,{})})}),so=i.forwardRef(function(e,r){const{children:t,portalled:s=!0,portalRef:n,backdrop:l=!0,...d}=e;return o.jsxs(w,{disabled:!s,container:n,children:[l&&o.jsx(x,{}),o.jsx(F,{children:o.jsx(P,{ref:r,...d,asChild:!1,children:t})})]})}),no=i.forwardRef(function(e,r){return o.jsx($,{position:"absolute",top:"2",insetEnd:"2",...e,asChild:!0,children:o.jsx(ro,{size:"sm",ref:r,children:e.children})})}),io=y,lo=L,co=q,ho=S,uo=x,go=v,xo=i.forwardRef(function(e,r){const{inputProps:t,label:s,description:n,addon:l,icon:d,indicator:c=o.jsx(E,{}),indicatorPlacement:h="end",...f}=e,j=s||n||d,R=c?O:i.Fragment;return o.jsxs(z,{...f,children:[o.jsx(H,{ref:r,...t}),o.jsxs(N,{children:[h==="start"&&c,j&&o.jsxs(R,{children:[d,s&&o.jsx(A,{children:s}),n&&o.jsx(U,{children:n}),h==="inside"&&c]}),h==="end"&&c]}),l&&o.jsx(W,{children:l})]})}),Co=X,fo=i.forwardRef(function(e,r){const{label:t,children:s,helperText:n,errorText:l,optionalText:d,...c}=e;return o.jsxs(G,{ref:r,...c,children:[t&&o.jsxs(J,{children:[t,o.jsx(K,{fallback:d})]}),s,n&&o.jsx(Q,{children:n}),l&&o.jsx(V,{children:l})]})}),jo=i.forwardRef(function(e,r){const{children:t,cite:s,citeUrl:n,showDash:l,icon:d,...c}=e;return o.jsxs(Y,{ref:r,...c,children:[d,o.jsx(Z,{cite:n,children:t}),s&&o.jsxs(_,{children:[l?o.jsx(o.Fragment,{children:"—"}):null," ",o.jsx("cite",{children:s})]})]})});export{jo as B,io as D,fo as F,to as P,Co as R,xo as a,uo as b,go as c,so as d,no as e,co as f,ho as g,lo as h};
