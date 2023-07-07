!start.
!captyBuffer. //Initial goal

+!start : true <- .print("Hello world.").

+fullR("rack")
  <- .print("Rack detected full.").

+emptyR("rack")
  <- .print("Rack detected empty.").

+!captyBuffer : play("movimentando")
 <- .wait(stop("movimentando"));
    !captyBuffer.

+!captyBuffer : fullB("buffer")
  <- !move_buffer;
     !captyBuffer.

+!captyBuffer : emptyB("buffer")
  <- .print("Esperando buffer.");
     .wait(fullB("buffer"));
     !captyBuffer.

+!captyBuffer
  <- .wait(fullB("buffer"));
     !captyBuffer.


+!move_buffer : emptyR("rack")
  <- embedded.mas.bridges.jacamo.defaultEmbeddedInternalAction("arduino1","mov_A",[]);
     .print("Buffer detected. Rack is empty.");
     embedded.mas.bridges.jacamo.defaultEmbeddedInternalAction("arduino1","capt_B",[]).
+!move_buffer : fullR("rack")
  <- embedded.mas.bridges.jacamo.defaultEmbeddedInternalAction("arduino1","mov_A",[]);
     .print("Buffer detected. Rack is full.");
     embedded.mas.bridges.jacamo.defaultEmbeddedInternalAction("arduino1","capt_R",[]);
     .wait(10000);
     .send(delivery,achieve,move_delivery);
     embedded.mas.bridges.jacamo.defaultEmbeddedInternalAction("arduino1","capt_B",[]);
     .wait(stop("movimentando")).
+!move_buffer
  <- .print("Buffer: Unidentified Rack.");
     +emptyB("buffer").

+!remove_delivery[source(Sender)] : emptyR("rack")
  <- embedded.mas.bridges.jacamo.defaultEmbeddedInternalAction("arduino1","mov_A",[]);
     .print("Delivery detected. Rack is empty.");
     embedded.mas.bridges.jacamo.defaultEmbeddedInternalAction("arduino1","capt_C",[]);
     .wait(3000);
     .send(delivery,achieve,move_delivery);
     .wait(stop("movimentando")).
+!remove_delivery[source(Sender)] : fullR("rack")
  <- .print("Delivery detected. Rack is full, not possible.").
+!remove_delivery[source(Sender)]
   <- .print("Delivery: Unidentified Rack.").



/*
!start.
!captyBuffer. //Initial goal

+!start : true <- .print("Hello world.").

+rack(1)
  <- .print("Rack detected full.").

+rack(0)
  <- .print("Rack detected empty.").

+!captyBuffer : movimentando(1)
 <- .wait(movimentando(0));
    !captyBuffer.

+!captyBuffer : buffer(1)
  <- !move_buffer;
     !captyBuffer.

+!captyBuffer : buffer(0)
  <- .print("Esperando buffer.");
     .wait(buffer(1));
     !captyBuffer.

+!captyBuffer
  <- .wait(buffer(1));
     !captyBuffer.


+!move_buffer : rack(0)
  <- embedded.mas.bridges.jacamo.defaultEmbeddedInternalAction("arduino1","mov_A",[]);
     .print("Buffer detected. Rack is empty.");
     embedded.mas.bridges.jacamo.defaultEmbeddedInternalAction("arduino1","capt_B",[]).
+!move_buffer : rack(1)
  <- embedded.mas.bridges.jacamo.defaultEmbeddedInternalAction("arduino1","mov_A",[]);
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
  <- embedded.mas.bridges.jacamo.defaultEmbeddedInternalAction("arduino1","mov_A",[]);
     .print("Delivery detected. Rack is empty.");
     embedded.mas.bridges.jacamo.defaultEmbeddedInternalAction("arduino1","capt_C",[]);
     .wait(3000);
     .send(delivery,achieve,move_delivery);
     .wait(movimentando(0)).
+!remove_delivery[source(Sender)] : rack(1)
  <- .print("Delivery detected. Rack is full, not possible.").
+!remove_delivery[source(Sender)]
   <- .print("Delivery: Unidentified Rack.").
*/
