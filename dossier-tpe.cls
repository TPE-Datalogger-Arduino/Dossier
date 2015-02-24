%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Classe de notre dossier %
%%%%%%%%%%%%%%%%%%%%%%%%%%%

\LoadClass[a4paper, 11pt]{report}

% --- Packages ---

\RequirePackage[frenchb]{babel}
\RequirePackage[utf8]{inputenc}
\RequirePackage[T1]{fontenc}
\RequirePackage{lmodern}
\RequirePackage{textcomp}
\RequirePackage[margin=2cm]{geometry}
\RequirePackage{fancyhdr}
\RequirePackage[usenames, dvipsnames]{xcolor}
\RequirePackage{graphicx}
\RequirePackage{tikz}
\RequirePackage{mdframed}
\RequirePackage{minted}
\RequirePackage{siunitx}
\RequirePackage{hyperref}

% --- Informations sur le PDF ---

\hypersetup{
	pdftitle={Releveur de données météorologiques},
	pdfauthor={Téofil Adamski, Rémi Bruyère, Sammy Plat \&{} et Clément Bidault},
	pdfsubject={Dossier de TPE},
	colorlinks=true, allcolors=red
}

% --- En-têtes ---

\pagestyle{fancy}

\headheight13.6pt

\fancyfoot{}
\lfoot{Dossier de TPE --- Releveur de données météorologiques}
\rfoot{\thepage}

\fancypagestyle{plain}{
	\renewcommand{\headrulewidth}{\z@}
	\fancyhead{}
}

% --- Page de garde ---

\renewenvironment{titlepage}
{%
	\thispagestyle{empty}%
	\setcounter{page}\z@
}%
{%
	\newpage
}

% --- Pour afficher les codes ---

\usemintedstyle{trac}

\newcommand{\FichierCode}[2]
{%
	\begin{mdframed}[linecolor=black!50, linewidth=3pt, innerleftmargin=6pt, rightline=false, topline=false, bottomline=false, backgroundcolor=black!3]
		\inputminted[fontsize=\footnotesize, linenos, numbersep=15pt]{#1}{#2}
	\end{mdframed}
}

\endinput
