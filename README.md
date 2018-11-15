# PA3
 Data Communication Networks – Fall 2018 
Investigating Backoff Protocols
Due Date: December 3, 2018 by 11:59pm CST (local time in Starkville)
Assignments can be done in pairs (undergraduate or graduate)
Your code must compile on Pluto. Please refer to the syllabus for penalties if your
code fails to compile.
Carefully follow the instructions for submitting your solution.


# 1. Assignment Objective
The objective of this assignment is to evaluate through simple simulation of three backoff protocols.
Your simulation code will be written in either C++ or Java and submitted through MyCourses (see the
submission instructions later in this document). You are also responsible for submitting a document
plotting your resulting data and explaining your findings (as a pdf).


# 2. Overview and Description of Backoff Protocols
This section provides a description of the three backoff protocols to be implemented. 
Your implemented simulation must align with this description. 
There is no requirement to simulate true concurrency, nor should you pursue such a goal (you are building a discrete-event simulation).
In your simulation, time is assumed to be discretized: a unit of time in the simulation is referred to as a
slot. 
Slots are indexed starting at 1. 
Assume that any data transmitted by a device can fit within a single slot. 
If only one device transmits in a slot, then the transmission is successful. 
Else, if two or more devices transmit in a slot, then this results in a collision; that is, this the respective transmissions fail
for all transmitting devices in that slot.
There are assumed to be N devices (see details for setting this later on in this specification). Each
device begins the simulation with a single packet to transmit. Once this packet is successfully
transmitted, the device is no longer active and you need not track its status in the simulation further.
Your simulation should not model the internal details of packets or the data transmitted (that is, this
simulation is not worried about frame structure or contents). For your simulations, you are only
concerned with whether 0,1, or more devices send within any particular slot.
The general structure for any backoff protocol is as follows. Starting from an initial time slot,
contiguous slots are grouped into windows W1, W2, W3… and so on. The size of a window Wj is the
number of slots in the window and this is denoted by | Wj |. In each window, a device selects a single
slot uniformly at random to attempt a transmission of its packet. If the transmission is successful in this
slot, the device terminates the protocol. Else, the transmission fails and the device waits until the end
of the current window and repeats the same actions for the next window.
Note: It is not the case that a device sends in each slot with some non-zero probability. Recall that we
talked in class about a qualitatively similar protocol where a device sends in each slot with probability
1/(window size). However, you are not to simulate that version for this assignment; follow the above
description instead.
The three backoff protocols you will analyze are different only in how the windows are defined.
Keeping this in mind should help simplify the structure of your code. The remainder of this section
succinctly defines the three protocols to be simulated.


# 2.1 Linear Backoff
You will start by implementing a backoff protocol named linear backoff. In this protocol, the initial
window size is 2 slots. Each subsequent window increases by 1 slot.
For example, |W1| = 2, |W2| = 3, |W3|=4, etc.


# 2.2 Binary Exponential Backoff
The next backoff protocol to be implemented is the familiar binary exponential backoff protocol. The
initial window size is 2 slots. Each subsequent window increases by a multiplicative factor of 2.
For example |W1| = 2, |W2| = 4, |W3|=8, etc.


# 2.3 Logarithmic Backoff
The third backoff protocol is called logarithmic backoff. Again, the initial window size is 2 slots. Each
subsequent window is defined as follows. For a current window Wj which has just ended, the next
window Wj+1 has (1 + 1/log2(|Wj|))*|Wj| slots; when this value is not an integer, you should take the
floor of the value. Note that the logarithm is base 2.
For example, |W1| = 2, |W2| = (1 + 1/log2(2))*2 = 4, |W3| = (1 + 1/log2(4))*4 = 6, etc.

# 3. Your Simulation Code
Your code should produce an executable named myBackoff. No other executables will be accepted
and your executable must follow this naming. There are no inputs to this executable.
Running this executable should produce output for each of the three protocols defined above in Section
2. The output of interest is the number of slots required to have all devices succeed; we will refer to
this metric as latency. An execution of myBackoff should produce latency values for each protocol
and write these to the following files:
linearLatency.txt
binaryLatency.txt
logLatency.txt
You must use these file names exactly. We will describe the format of this output momentarily.
The execution of myBackoff will run trials of these protocols. A trial is a single execution of one
protocol for N devices.
For each protocol, the first trial will use N=100 devices, and each subsequent trial will increase this by
100 more devices. For example, an execution will run linear backoff with 100 devices, then with 200
devices, then 300 devices, etc. all the way up to N=6000 devices.
Each trial will be repeated 10 times per N value. For example, the first trial for linear backoff will run
10 simulations with 100 devices, then 10 simulations with 200 devices, and so on. This allows us to
avoid unlucky executions of the protocol (which is randomized).
For each trial, the corresponding text file should contain the average latency only. For example, for the
first trial of linear backoff, the average latency over 10 repetitions will be written to
linearLatency.txt. Each value must be on its own line.
In measuring the latency in your simulation, remember to count up to the time that the last device
finishes (note this is different from the entirety of the current window if all devices finish prior to this
point). For example, consider linear backoff executing in a window of size 5. If the last device
succeeds in the 3rd slot of this window, then that is the point (including this slot) up to which you
should count the latency, rather than counting all 5 slots in the current window. In particular, the
latency would be 2 + 3 + 4 + 3 = 12 since the initial window size is 2, the next is 3, the next is 4, and 3
slots of the last window were required before all devices finished. The number 12 would be written on
a single line in linearLatency.txt.
Your code must compile on Pluto. We will verify that your code produces the
correct files. You must include a makefile that creates your executable
myBackoff.


# 4. Your Brief Writeup
You must present the findings of your simulations. In particular, you must plot your data for the three
protocols on a single graph where the x-axis is the number of devices (increasing by 100 in each trial)
and the y-axis is the average latency. Both axes must be labeled.
It should be clear which points correspond to which protocol and there should be a legend with the
necessary labeling to make this clear. You may join the points within each protocol by a “trend line” if
you wish, but it is not necessary. No error analysis is necessary.
You may plot this using any program you wish; however, you are not to plot this by hand. So long as
the plot meets the requirements mentioned above, and is of sufficient size to be read clearly, the
particulars of how you accomplish this is up to you.
In addition to the plot, you should give a brief report on your findings; this should be at most a couple
paragraphs. You should answer the following questions:

1. Which backoff protocol appears to give the best (lowest) average latency value as the number of
devices tends to infinity?

2. Which backoff protocol appears to give the second best (lowest) average latency value as the
number of devices tends to infinity?

3. Which backoff protocol appears to give the third best (lowest) average latency value as the number
of devices tends to infinity? This is the worst of the three protocols you implemented.


# 5. Your Submitted Solution
5.1 Due Date
This assignment is due on December 3, 2018 by 11:59pm CST (local time in Starkville).


# 5.2 Hand in Instructions
(i) You must hand in the following files:
- Source code files with your name at the top of your code
- Makefile: your code must compile and link cleanly by typing ``make’’
- Your report on your findings (as described in Section 4) with your plot embedded in the
document; if the plot is separate, you will lost 5 points. This must be in pdf format and the
file must be of reasonable size (less than 5 MB)

(ii) Submit your files in a single compressed file, either .zip or .tar; no other compression format
will be considered. This compressed file must be titled (do not include the square brackets):
[your NetID]-PA3.tar or [your NetID]-PA3.zip
for example, I would title mine: my325-PA3.tar or my325-PA3.zip
If you are working with a partner, put a hyphen between the NetIDs like so:
[NetID1-NetID2]-PA3.tar

(iii) Both your report and your source code MUST have the names of the author(s) on it! If you are
working as a pair, only one student should submit the code through MyCourses.
Your implementation will be tested on the Pluto system, and so it must run smoothly in this
environment! If your code does compile and run correctly on this system, you will lose points as
specified in the syllabus and covered in class. There will be no exceptions to this rule.


# 5.3 Documentation
Since there is no external documentation required for this assignment, you are expected to have a
reasonable amount of internal code documentation (to help the graders read your code).
5
