#!/usr/bin/Rscript
args <- commandArgs(TRUE)
X11()
data <- read.table(args[1], col.names=c('x','y') ,sep=",", quote="\"")
# Creating a Graph
attach(data)
plot(x, y, col= 'blue', xlab="XValue", ylab="Yvalue") 
calcul <- read.table("~/Exercises/LMS/Rcalculate.calc", col.names=c('a','b') ,sep=";", quote="\"")
attach(calcul)
j = x
i = a *j + b
lines (j, i, col='red')
title("Regression of y on x")
#summary(lm(y~x))
message("Press Return To Continue")
invisible(readLines("stdin", n=1))
