# Postmortem: Software Outage on May 30, 2024

![An image of the command line where repeated ssh attempts result in “port 22: connection refused.”](https://miro.medium.com/max/2104/1*aNsuz7CGA7AGQ9LdjY4xlA.png)

# Issue Summary:

Duration: The outage lasted from 10:15 AM to 12:45 PM (EST) on May 30, 2024.
Impact: During this period, our primary web service was completely unavailable. Users experienced 503 Service Unavailable errors, and approximately 80% of our user base was affected.
Root Cause: The root cause was a misconfigured load balancer that failed to distribute traffic correctly, causing server overloads.

#Timeline:

-	10:15 AM: Issue detected via monitoring alerts indicating high server error rates.
-	10:17 AM: Operations team received multiple customer complaints about service unavailability.
-	10:20 AM: Initial investigation focused on server health, suspecting possible DDoS attack.
-	10:35 AM: Networking team joined the investigation to analyze traffic patterns.
-	11:00 AM: Misleading path: assumed database overload due to coinciding peak usage time.
-	11:20 AM: Escalated to infrastructure team after database metrics appeared normal.
-	11:45 AM: Load balancer misconfiguration identified as the root cause.
-	12:00 PM: Load balancer settings corrected and traffic distribution normalized.
-	12:30 PM: Gradual recovery observed as services started to return to normal.
-	12:45 PM: Full service restored and confirmed stable.

# Root Cause and Resolution:

-	Root Cause: The issue stemmed from a recent update to the load balancer configuration. A setting intended to improve performance inadvertently caused the load balancer to misroute traffic, overwhelming certain servers while leaving others underutilized.
- 	Resolution: Upon identifying the misconfiguration, the infrastructure team reverted the load balancer settings to the previous stable state. A phased restart of the affected servers was conducted to evenly distribute the traffic and ensure stability.

# Corrective and Preventative Measures:

## Improvements:

-	Enhance monitoring to detect load balancer configuration issues.
-	Implement automated failover procedures to redistribute traffic in case of load balancer failure.
-	Increase cross-team training on load balancer management and monitoring.

## Tasks:

-	Audit Load Balancer Settings: Conduct a comprehensive review of current load balancer settings and document best practices.
-	Enhance Monitoring: Develop and deploy new monitoring alerts specifically for load balancer performance and traffic distribution anomalies.
-	Automate Failover: Create and test scripts for automated traffic redistribution in case of load balancer malfunctions.
-	Training Sessions: Organize regular training sessions for the operations, networking, and infrastructure teams on identifying and resolving load balancer-related issues.
-	Update Documentation: Update internal documentation to reflect the changes in load balancer configurations and the steps taken to resolve the outage.
-	By implementing these measures, we aim to prevent similar issues in the future and ensure a more robust and resilient service infrastructure.
