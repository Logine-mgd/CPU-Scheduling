# CPU-Scheduling
CPU Scheduling algoritms FCFS (First Come First Serve) , RR (Round Robin) , SPN (Shortest Process Next), SRT (Shortest Remaining Time) ,HRRN (Highest Response Ratio Next) , FB-1 (Feedback where all queues have q=1)
## Input format
Input Format:
Line1. “trace” or “stats”.
“trace” is used to ask  program to visualize the processes switching over the CPU 
“stats” is used to ask program to write some statistics on the scheduled processes 
used to visualize the processes
Line2. a comma-separated list telling which CPU scheduling policies to be analyzed/visualized along with
their parameters, if applicable. Each algorithm is represented by a number as listed in the
introduction section and as shown in the attached testcases.
Round Robin has a parameter specifying the quantum q to be used. Therefore, a policy
entered as 2-4 means Round Robin with q=4.
Line3. An integer specifying the last instant to be used in your simulation and to be shown on the timeline.
Check the attached testcases.
Line4. An integer specifying the number of processes to be simulated. None of the processes is making a
blocking call.
Line5. Start of description of processes. Each process is to be described on a separate line. For algorithms
1 through 7, each process is described using a comma-separated list specifying:
- One character specifying a process name
- Arrival Time
- Service Time
## Input  Example 
trace
7
20
5
A,0,3
B,2,6
C,4,4
D,6,5
E,8,2
