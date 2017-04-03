#!/usr/bin/Rscript
args <- commandArgs(TRUE)
x11(width = 20, height = 12, pointsize = 12)
# Creating a Graph
par(mfrow=c(3,1))
data <- read.table(args[1], col.names=c('x','y') ,sep=",", quote="\"")
attach(data)
plot(x, y, col= 'blue', main="Regression of y on x (statistical way)" , xlab="XValue", ylab="Yvalue") 
calcul <- read.table("~/Exercises/LMS/Rcalculate.calc", col.names=c('a','b') ,sep=";", quote="\"")
attach(calcul)
j = x
i = a *j + b
lines (j, i, col='red')
summary(lm(y~x))
datanor <- read.table("~/Exercises/LMS/RcalculateStep.normalize", col.names=c('c','d') ,sep=";", quote="\"")
attach(datanor)
plot(c, d, col= 'blue', main="Regression of y on x (Machine Learning)" , xlab="XValue", ylab="Yvalue")
calculnor <- read.table("~/Exercises/LMS/RcalculateStep.calc", col.names=c('e','f') ,sep=";", quote="\"")
attach(calculnor)
j = c
i = e *j + f
lines (j, i, col='red')
summary(lm(d~c))
error <- read.table("~/Exercises/LMS/error.calc", col.names=c('m','n') ,sep=";", quote="\"")
attach(error)
plot(m, n, col= 'blue', main="Error with respect to Iterations" , xlab="Iterations", ylab="Error")
#summary(lm(y~x))
message("Press Return To Continue")
invisible(readLines("stdin", n=1))
