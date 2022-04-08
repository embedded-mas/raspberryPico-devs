
!start.

+!start : true <- .print("hello world.").

+light_state1(0)
   <- .print("Tenho que apagar o LED 1");
       embedded.mas.bridges.jacamo.defaultEmbeddedInternalAction("RaspBPP1","lightOff1",[]);
       .print("Apaguei o LED 1").


+light_state1(1)
   <- .print("Tenho que acender o LED 1");
       embedded.mas.bridges.jacamo.defaultEmbeddedInternalAction("RaspBPP1","lightOn1",[]);
       .print("Acendi o LED 1").


+light_state2(0)
   <- .print("Tenho que apagar o LED 2");
       embedded.mas.bridges.jacamo.defaultEmbeddedInternalAction("RaspBPP1","lightOff2",[]);
       .print("Apaguei o LED 2").


+light_state2(1)
   <- .print("Tenho que acender o LED 2");
       embedded.mas.bridges.jacamo.defaultEmbeddedInternalAction("RaspBPP1","lightOn2",[]);
       .print("Acendi o LED 2").
