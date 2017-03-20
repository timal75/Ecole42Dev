#!/usr/bin/Rscript
args <- commandArgs(TRUE)
X11()
data <- read.table("~/Exercises/LMS/error.calc", col.names=c('a','b') ,sep=";", quote="\"")
# Creating a Graph
attach(data)
plot(a, b, col= 'blue', xlab="Iter", ylab="Error") 
title("Error with respect to iteration")
#summary(lm(y~x))
message("Press Return To Continue")
invisible(readLines("stdin", n=1))
