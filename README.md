# query-scheduler
QUES 5: Sudesh Sharma is a Linux expert who wants to have an online system where he can handle student queries. Since there can be multiple requests at any time, he wishes to dedicate a fixed amount of time to every request so that everyone gets a fair share of his time. He will log into the system from 10am to 12am only. He wants to have separate requests queues for students and faculty, where faculty queue is given a higher priority. Implement a strategy for the same. The summary at the end of the session should include the total time he spent on handling queries and average query time.

Description:

CONCEPT USED:

The main concept which I have in this project is scheduling of processes as numbers of query can come at the same time and we have to give equal time to each of the query 
So, I have used round robin scheduling as I have to give equal time to every query and round robin works on this principle only. 
In round robin, time slices are assigned to each process in equal portions and in circular order, handling all processes without priority.
Round robin is simple and starvation scheduling algorithm.
