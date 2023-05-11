hi CursorColum cterm=none ctermbg=DarkCyan ctermfg=White
set number
set smartcase 
set ignorecase
set hlsearch
set ruler
set relativenumber

set expandtab
set tabstop=4
set shiftwidth=4
set softtabstop=4

set laststatus=2

hi User1 guifg=gray
hi User2 guifg=red
hi User3 guifg=white

set statusline =%2*%n%m%r%h%w%*\ %F\ %1*[FORMAT=%2*%{&ff}:%{&fenc!=''?&fenc:&enc}%1*]\ [TYPE=%2*%Y%1*]\ [COL=%2*%03v%1*]\ [ROW=%2*%03l%1*/%3*%L(%p%%)%1*]\]

inoremap ( ()<Esc>i
inoremap " ""<Esc>i
inoremap ' ''<Esc>i
inoremap [ []<Esc>i
inoremap {{ {}<Esc>i
inoremap {<CR> {<CR>}<Esc>ko
set smartindent
set nohlsearch
colorscheme slate
