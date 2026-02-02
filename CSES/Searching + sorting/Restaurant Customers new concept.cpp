/*
It’s a classic sweep line / event counting problem.

Core idea 💡 (sweep line)
Instead of thinking per customer, think in terms of events:

Arrival → +1 customer
Departure → −1 customer

Then:
Sort all events by time
Sweep from left to right
Keep a running count
Track the maximum
*/

// THIS METHOD IS ONLY FOR OVERLAPPING TIMINGS 