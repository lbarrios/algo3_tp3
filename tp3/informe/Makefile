LATEX = pdflatex
OPTS  = --shell-escape # La condicion OPTS es para que compile con imagenes .eps

.PHONY: all clean clean-output

all: clean clean-output informe

informe:
  @$(LATEX) $(OPTS) informe.tex > /dev/null # Lo corremos dos veces, la primera para que se haga bien el índice
  $(LATEX) $(OPTS) informe.tex

clean-output: clean
  @rm -f build

clean:
  rm -f *.log *.aux *.toc
