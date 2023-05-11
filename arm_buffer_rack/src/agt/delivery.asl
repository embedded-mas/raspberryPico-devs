!start.

+!start : true
  <- .print("Hello, I'm a car.").
/*
+ok
  <- .print("Button pressed.");
     .send(sample_agent,achieve,remove_delivery).

{ include("$jacamoJar/templates/common-cartago.asl") }
*/

+!move_delivery[source(Sender)]
  <- .print("Delivery moved").
















/*
!start.

+!start : true
  <-  .print("Hello world.\n          I'm Bob.");
      .send(sample_agent,tell,hello).

-!start
  <- .wait(1000);
     !start.

+hello[source(sample_agent)]
  <- !luck.

+!luck : true
  <-  .random([0, 1, 2, 3, 4, 5, 6], N);
      .print("Sample_agent, move to pos: ", N);
      .send(sample_agent,achieve,pos(N));
      .wait(10000);
      !luck.
*/
