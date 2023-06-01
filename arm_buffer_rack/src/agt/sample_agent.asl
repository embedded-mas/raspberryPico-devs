
!start.
!emptyBuffer.

+!start : true <- .print("Hello world.").

+rack(1)
  <- .print("Rack detected full.").

+rack(0)
  <- .print("Rack detected empty.").

+!emptyBuffer : movimentando(1)
 <- .wait(movimentando(0));
    !emptyBuffer.

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


+!move_buffer : rack(0)
  <- +movimentando(1);
     .print("Buffer detected. Rack is empty.");
     embedded.mas.bridges.jacamo.defaultEmbeddedInternalAction("arduino1","capt_B",[]).
+!move_buffer : rack(1)
  <- +movimentando(1);
     .print("Buffer detected. Rack is full.");
     embedded.mas.bridges.jacamo.defaultEmbeddedInternalAction("arduino1","capt_R",[]);
     .wait(10000);
     .send(delivery,achieve,move_delivery);
     embedded.mas.bridges.jacamo.defaultEmbeddedInternalAction("arduino1","capt_B",[]);
     .wait(movimentando(0)).
+!move_buffer
  <- .print("Buffer: Unidentified Rack.");
     +buffer(0).

+!remove_delivery[source(Sender)] : rack(0)
  <- +movimentando(1);
     .print("Delivery detected. Rack is empty.");
     embedded.mas.bridges.jacamo.defaultEmbeddedInternalAction("arduino1","capt_C",[]);
     .wait(3000);
     .send(delivery,achieve,move_delivery);
     .wait(movimentando(0)).
+!remove_delivery[source(Sender)] : rack(1)
  <- .print("Delivery detected. Rack is full, not possible.").
+!remove_delivery[source(Sender)]
   <- .print("Delivery: Unidentified Rack.").


















/*
   !start.

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


   +!move_buffer : rack(0)
     <- .print("Buffer detected. Rack is empty.");
        embedded.mas.bridges.jacamo.defaultEmbeddedInternalAction("arduino1","capt_B",[]).
   +!move_buffer : rack(1)
     <- .print("Buffer detected. Rack is full.");
        embedded.mas.bridges.jacamo.defaultEmbeddedInternalAction("arduino1","capt_R",[]);
        .wait(10000);
        .send(delivery,achieve,move_delivery);
        embedded.mas.bridges.jacamo.defaultEmbeddedInternalAction("arduino1","capt_B",[]).
   +!move_buffer
     <- .print("Buffer: Unidentified Rack.");
        +buffer(0).

   +!remove_delivery[source(Sender)] : rack(0)
     <- .print("Delivery detected. Rack is empty.");
        embedded.mas.bridges.jacamo.defaultEmbeddedInternalAction("arduino1","capt_C",[]);
        .wait(3000);
        .send(delivery,achieve,move_delivery).
   +!remove_delivery[source(Sender)] : rack(1)
     <- .print("Delivery detected. Rack is full, not possible.").
   +!remove_delivery[source(Sender)]
      <- .print("Delivery: Unidentified Rack.").
*/
