# Homework 03 - Stacks and Queues -

Name: Aidan Schrier

Github Account name: Ari-Schrier

How many hours did it take you to complete this assignment (estimate)? 
I would estimate about five hours, but I spent much longer than that working through technical issues with the khoury servers.

Did you collaborate with any other students/TAs/Professors? If so, tell us who and in what capacity.  
Professor Lionel helped me with testing


Did you use any external resources (you do not have to cite in class material)? (Cite them below)  
- I read the wikipedia article on circular buffers
- I used an article I found from andrew.cmu.edu, but was unable to find much information about the author
A. Unknown, “Stacks and Queues,” Stacks and queues, n.d.. [Online]. Available: https://www.andrew.cmu.edu/course/15-121/lectures/Stacks%20and%20Queues/Stacks%20and%20Queues.html. [Accessed: 30-Jan-2023]. 


(Optional) What was your favorite part of the assignment? 
I actually really enjoyed running my code through a a debugger. This was my first time experimenting with one.

(Optional) How would you improve the assignment? 
As I think I've said on every assignment so far, far more of my time is spent fighting with the khoury servers than is spent coding. If homework one had been a lab, all of my past homework would have been much less of a struggle.

## Further Thinking Questions

1. Circular queues are used quite a bit in operating systems and high performance systems, especially when performance matters. Do a little outside research, and answer this question specifically: Why is a ring buffer useful and/or when should it be used? 

  A ring buffer is usesful because it allows the user to add and remove data without shuffling around an array every time. I can remove an element in slot 0 of an array, and not immediately need to move everything from slots 1-x down a slot. Moving that data would be a very computationally expensive task. Another large upside to a queue is that I can add information to the end of it while working with the front. If my program discovers something that will need to be handled down the line, I can continue my current process and know that my circular queue will get to it eventually.

  I had a much easier time conceptualizing a queue once I learned about its application in a breadth-first search. Running a breadth-first search on a graph, one checks each node and adds every unexplored node to the back of the queue. Once one is done working on, say, node A, you simply have to move the front to the first node it discovered. Another use I can think of for ring buffers is simulating any kind of a literal queue. As (tasks? Customers? anything) come up on the front of the queue, more can be added to the back without disturbing my ability to deal with whatever is in front of me.

2. We are going to talk about stacks quite a lot in this course, so it will be important to understand them. Do a little outside research, and edit this section of the readme answering specifically: Why is a stack useful and/or when should it be used?

  A stack is useful because it allows for recursion. It's also very fast, and very simple. Once something is on the stack, it's locked in. If a queue is useful in a breadth-first search, a stack is useful for a depth-first search. I liked an example that I read of using a stack to solve a maze. Every time one reaches a turn, they add both directions they could turn to the stack. No matter how deep down one path of the maze one goes, once they hit a dead end they immediately know where to try next. 

  Weirdly enough, I am most familiar with stacks from my hobby-- a card game called Magic. In this game, actions that the players take are resolved using a stack. If I tell my dragon to attack you, that attack goes on the stack. You then are given the opportunity to add something to the stack, perhaps a spell to kill my dragon. I can respond with a spell to change the target of the spell below it on the stack. To resolve this situation, we use first-in-first-out. We look at my spell, I change your spell's target to your minotaur. We remove it from the stack. We look at your spell. It kills your minotaur. We remove it from the stack. My dragon's attack finally proceeds unscathed.



For each of these questions, we are expecting your answer to be in the range of 2-3 paragraphs (can include complexity, example usage, pros/cons, etc). Make sure to cite your sources. It is recommended you use [IEEE citation style](https://owl.purdue.edu/owl/research_and_citation/ieee_style/ieee_overview.htm) as it is most common for CS papers and research. 


## Important notes

* Your code **must compile and run** on the Khoury machines to earn credit. Make sure you test your programs on these machines, as this is where we grade your assignments.
* You must commit any additional files(if any) into your repository so we can test your code.
  * Points will be lost if you forget!
* Do not forget, once you have pushed your changes to your repo make sure that you **submit them to Gradescope before the assignment deadline!**

