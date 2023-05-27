!start.
//!emptyBuffer.

+!start : true <- .print("Hello world.").

+buffer(1)
  <- !move_buffer.

+rack(1)
  <- -rackEmpty;
     .print("Rack detected full.");
     +rackFull.

+rack(0)
  <- -rackFull;
     .print("Rack detected empty.");
     +rackEmpty.

/*
+!emptyBuffer : buffer(1)
  <- !move_buffer;
     !emptyBuffer.

+!emptyBuffer : buffer(0)
  <- .print("Esperando buffer.");
     .wait(buffer(1));
     !emptyBuffer.

+!emptyBuffer
  <- .wait(buffer(1));
     !emptyBuffer.
*/

+!move_buffer : rackEmpty
  <- .print("Buffer detected. Rack is empty.");
     embedded.mas.bridges.jacamo.defaultEmbeddedInternalAction("arduino1","capt_B",[]).
+!move_buffer : rackFull
  <- .print("Buffer detected. Rack is full.");
     embedded.mas.bridges.jacamo.defaultEmbeddedInternalAction("arduino1","capt_R",[]);
     .wait(10000);
     .send(delivery,achieve,move_delivery);
     embedded.mas.bridges.jacamo.defaultEmbeddedInternalAction("arduino1","capt_B",[]).
+!move_buffer
  <- .print("Buffer: Unidentified Rack.");
     +buffer(0).

+!remove_delivery[source(Sender)] : rackEmpty
  <- .print("Delivery detected. Rack is empty.");
     embedded.mas.bridges.jacamo.defaultEmbeddedInternalAction("arduino1","capt_C",[]);
     .wait(3000);
     .send(delivery,achieve,move_delivery).
+!remove_delivery[source(Sender)] : rackFull
  <- .print("Delivery detected. Rack is full, not possible.").
+!remove_delivery[source(Sender)]
   <- .print("Delivery: Unidentified Rack.").




















/*
!start.

+!start : true <- .print("Hello world.").

+buffer(1)
  <- .print("Buffer detected");
     embedded.mas.bridges.jacamo.defaultEmbeddedInternalAction("arduino1","capt_B",[]).
+rack(1)
  <- .print("Rack detected");
     embedded.mas.bridges.jacamo.defaultEmbeddedInternalAction("arduino1","capt_R",[]).
+car(1)
  <- .print("Car detected");
     embedded.mas.bridges.jacamo.defaultEmbeddedInternalAction("arduino1","capt_C",[]).

+buffer(0)
  <- .print("Arm removed from Buffer").

+rack(0)
  <- .print("Arm removed from Rack").

+car(0)
  <- .print("Arm removed from Car").

*/
