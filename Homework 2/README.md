Question 5: 
From Question2, what issues may happen if the robot that finished the
task is assigned a new task immediately? And what will be a potential
solution for the issues?

----------------------------------------------------------------------------

When a robot that has just completed a task is immediately assigned a
new task that requires the same resources, it can lead to a situation
where it continues to lock the shared resource. This prevents other 
robots from accessing the resource, potentially leading to deadlocks 
where multiple robots are waiting for each other to release resources.

If the robot releases the resource immediately after completing its 
task, and then has to wait for the resource to become available again 
for its next task, this leads to inefficient utilization of both the 
robot and the resource. The time spent waiting could have been used 
for task execution if a more strategic resource management approach 
was in place.

This system should manage the allocation and release of resources based
on task priorities and dependencies. It should ensure that resources are
allocated to tasks in an order that maximizes efficiency and minimizes
idle time.

Introducing a task queue where tasks are not only ordered by their arrival
or priority but also by their resource requirements would allow tasks to 
be re-ordered as priorities or resource availability changes.

Developing a system where the task queue is regularly analyzed to decide 
whether a robot should keep a resource locked (if its next task is 
coming up soon and requires the same resource) or release it (if another
robot has a more urgent task requiring that resource) would be a more
complex system and should consider the current state of the queue and the
estimated times for task completions.

Currently, each task is completed in the same time, but with these
potential solutions, a new definition of the tasks that better fits real
scenarios would be beneficial when accessing the priotization of a task.

----------------------------------------------------------------------------

Question 6:
From Question3, what issues you might obtain during the development of
the program? What issues do you think will happen if some of the actions,
e.g., waking up the ATC, checking the traffic pattern, entering the traffic
pattern, diverging to another airport, etc., take time to finish? And what
will be a potential solution for the issues?

----------------------------------------------------------------------------

In the development of the program, I faced issues regarding the timing of
each airplane and when they were arriving to the airspace. By adding more 
realistic times to the events of waking up the ATC, checking the traffic 
pattern, entering the traffic pattern, diverging to another airport, and 
more, the program would probably break because of how quick the airplanes
were trying to connect to the airspace. If not immediate, after the first
pilot were to try to establish connection, because of the time it would
take to wake up the ATC, the definition of the ATC being awake, and the 
point where the mutex would be locked between the pilot and the ATC would 
allow the next few airplanes to arrive and attempt to connect at the same
time. 

A potential fix would be to add some buffer between the pilots could be 
warrented, though this would affect the real outcome that two pilots might
actually contact at the same time. Contrastly, the pilots should have a 
buffer in their waiting period. By this, I mean that true pilots don't 
expect the ATC to be immediate. They expect there to be a few seconds delay.
The pilots in this case should have a period where they attempt to contact
and are able to wait. An approaching aircraft, should be accessing what is 
happening in the airspace and in the traffic pattern. To simulate this, 
there should be an open channel where all communication between the pilots
and the ATC happen between. This channel could look like a secondary class,
lets call it the operator, where the pilots reach out to the operator to be
connected to the ATC. This request is publically accessable by all the other
pilots in real time. Likewise, the ATC can analyze this operator class.

This operator class would be my attempt to merge the connections between all
pilots and ATC members just like the radio comms. All pilots can "tune" in
to the operator and listen to any communication. If there are pilots and ATC
actively communicating over the operator, they can buffer, assess the calls
and make a decision of when to contact ATC. If they attempt to contact,
rather then waiting for the ATC to recieve the message while their resource
is already locked, the operator will hold a queue of airplane requests so 
that the ATC can read the incomming requests. As for the logic of the airspace,
the ATC can be in communication with a pilot about clearing their landing,
but while the landing is completing, the ATC can assess any requests to enter
the airspace. Requests to control the airspace should have priority until it
is free to clear more landings.
