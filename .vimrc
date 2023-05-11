set nocompatible              " be iMproved, required
filetype off                  " required

" set the runtime path to include Vundle and initialize
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()
" alternatively, pass a pa where Vundle should install plugins
"call vundle#begin('~/some/path/here')

" let Vundle manage Vundle, required
    Plugin 'VundleVim/Vundle.vim'
    Plugin 'flazz/vim-colorschemes'
    Plugin 'scrooloose/nerdtree'
    Plugin 'jistr/vim-nerdtree-tabs'
    Plugin 'vim-airline/vim-airline'
    Plugin 'vim-airline/vim-airline-themes'
    Plugin 'w0rp/ale'

call vundle#end()            " required
filetype plugin indent on    " required
" To ignore plugin indent changes, instead use:
"filetype plugin on
"
" Brief help
" :PluginList       - lists configured plugins
" :PluginInstall    - installs plugins; append `!` to update or just :PluginUpdate
" :PluginSearch foo - searches for foo; append `!` to refresh local cache
" :PluginClean      - confirms removal of unused plugins; append `!` to auto-approve removal
"
" see :h vundle for more details or wiki for FAQ
" Put your non-Plugin stuff after this line
set bg=dark
set cursorline
colorscheme molokai

hi LineNr cterm=bold ctermfg=DarkGrey ctermbg=NONE
hi CursorLine cterm=underline ctermbg=DarkMagenta ctermfg=White
syntax enable
set number
set smartcase 
set ignorecase
set hlsearch
set ruler
set relativenumber

set expandtab
set tabstop=8
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
inoremap ;; <Esc>
set autoindent
set hlsearch
set t_Co=256
nnoremap <leader>n :NERDTreeFocus<CR>
nnoremap <C-n> :NERDTree<CR>
nnoremap q :NERDTreeToggle<CR>
nnoremap <C-f> :NERDTreeFind<CR>
hi Comment ctermfg=lightblue
hi String ctermfg=yellow
autocmd VimEnter * NERDTree
" enable tabline
let g:airline#extensions#tabline#enabled = 1
" set left separator
let g:airline#extensions#tabline#left_sep = ' '
" set left separator which are not editting
let g:airline#extensions#tabline#left_alt_sep = '|'
" show buffer number
let g:airline#extensions#tabline#buffer_nr_show = 1
"set mouse=a 
let g:NERDTreeMouseMode=3  
nnoremap <tab> :bn<CR>
"set guifont=consolas\ 16
set mouse=a
set cursorline
" ale setting
let g:ale_sign_column_alway=2
let g:ale_sign_error='❌'
let g:ale_sign_warning='>>'
let g:ale_statusline_formate=[' %d',' %d',' OK']
let g:ale_echo_msg_format='[%linter%] %code: %%s'
let g:ale_lint_on_text_changed='normal'
let g:ale_lint_on_insert_leave=1
let g:ale_c_gcc_options='-Wall -O2 -std=c99'
let g:ale_cpp_gcc_options='-Wall -O2 -std=c++14'
let g:ale_c_cppcheck_options=''
let g:ale_cpp_cppcheck_options=''
