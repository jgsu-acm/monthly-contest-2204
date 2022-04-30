\NeedsTeXFormat{LaTeX2e}
\ProvidesClass{ctsol}[2021/11/30 v1.0 Contest Solution Template document class]

\LoadClass[lang=cn,color=blue]{elegantbook}

\renewcommand{\thechapter}{\Alph{chapter}.}
\renewcommand{\chaptername}{\thechapter}

\makeatletter
\renewcommand{\maketitle}
{
    \clearpage
    \thispagestyle{empty}
    \begin{center}
        \LARGE
        \textbf{\@title} \par
        \normalsize
        \vspace{0.5cm}
        \@date
    \end{center}
}

% from https://tex.stackexchange.com/questions/271062/labeling-a-text-and-referencing-it-later
\newcommand{\labeltext}[2]
{
    \@bsphack
    \csname phantomsection\endcsname
    \def\@currentlabel{#1}{\label{#2}}
    \@esphack
}
\makeatother

\newcounter{solamo}
\newcommand{\addsolution}[3]
{
    \stepcounter{solamo}
    \labeltext{#1}{pro:\thesolamo}
    \labeltext{#2}{aut:\thesolamo}
    \labeltext{#3}{ans:\thesolamo}
}

\newcounter{solcnt}
\newcommand{\makesolution}
{
    \stepcounter{solcnt}
    \chapter{\ref*{pro:\thesolcnt}}
}

\RequirePackage{tabularx,booktabs} 
\newcolumntype{M}{>{\centering\arraybackslash}X}

\newcommand{\solutiontab}
{
    \begin{center}
        \begin{tabularx}{\textwidth}{MMMM}
            \toprule
            \textbf{题目编号} & \textbf{题目名称} & \textbf{命题人} & \textbf{做法} \\
            \midrule
        \end{tabularx}
    
        \newcounter{i}
        \setcounter{i}{1}
        \whiledo{\value{i}<\numexpr\value{solamo}+1\relax}
        {
            \begin{tabularx}{\textwidth}{MMMM}
                \Alph{i} & \ref*{pro:\thei} & \ref*{aut:\thei} & \ref*{ans:\thei} \\
                \ifnum \value{i}=\value{solamo}
                    \bottomrule
                \fi
            \end{tabularx}
            \stepcounter{i}
        }
    \end{center}
}

\RequirePackage{sourcecodepro}
\newcounter{stdcnt}
\newcommand{\std}[1]{
    \lstinputlisting[
        language=c++,
        frame=none,
        numbers=left,
        breaklines=true,
        xleftmargin=.25in,
        xrightmargin=.25in
    ]{../std/#1.cpp}
}