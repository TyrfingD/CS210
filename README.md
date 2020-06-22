# CS210
My work for the Programming Languages course
Currently includes my Project 2 file

#Summarize the project and what problem it was solving.
This goal of this project was to create a banking app. This app allows a user to see how much they would make in interest over any number of years given any initial investment, monthly deposit, and interest rate.

#What did you do particularly well?
Aside from the suspicion that this is the only one of the 3 class projects I created that performs the function it is supposed to perform, I am specifically proud of my organization in this code. My main function contains only the code that I think helps to understand the process of the program's primary loop. The remaining actions of the code are performed by 3 distinct functions that are called by main when necessary.

#Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?
I think the biggest improvement I could make to my code would be in the requestInput function. I would like to have been able to ensure my code could accept any user input for the variables in any format, ignoring symbols like $ and %. That way, I could delete the output lines stipulating the proper number format to the user.
I would also like to have seen how a proper pause works. One that waits for a user to continue but does not need a specific variable to input.
I attempted to include both improvements in my code, but I suspect it may be a specific quirk of my compiler that left me unable to see them work.

#Did you find writing any piece of this code challenging, and how did you overcome this? What tools and/or resources are you adding to your support network?
For me, the most difficult section of this code to write was the function that calculates the monthly/yearly investment and account balance. Even though we were given the calculations for this process in, converting that into code proved to be a challenge. Eventually, after much work, and talking it out through the discussion boards, I was able to find my errors in logic (I wasn't even updating all the right variables at first), change my single for loop into a nested double loop, and write a function that gives the proper output.

#What skills from this project will be particularly transferable to other projects and/or course work?
The functions of this project seem fundamental. I think everything I learned from this project will be applicable to future work. From proper formatting and commenting etiquette, to compartmentalization into functions, error handling, and constructing loops that properly update variables.

#How did you make this program maintainable, readable, and adaptable?
I believe I answered this in my response to the second question. In addition to my use of functions, I also tried to align my comments, calculations, and declarations whenever it seemed appropriate.
