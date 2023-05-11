package tools;

import javax.swing.*;
import java.awt.event.*;
import cartago.*;
import cartago.tools.*;

/*
 * 
 * Implementação de um artefato, que é um elemento sobre o qual o agente tem percepções e sobre o qual pode atuar.
 * Neste caso, o artefato tem uma interface gráfica composta de um botão que, quando pressionado, emite um sinal
 * com o conteúdo "ok", que é percebido pelos agentes.
 * 
 */
public class MySimpleGUI extends GUIArtifact {

	private MyFrame frame;
	
	public void setup() {
		frame = new MyFrame();
		//ligação entre o pressionamento do "okButton" que está contido na interface gráfica, com a operação (internal operation) "ok".
		linkActionEventToOp(frame.okButton,"ok"); 

		frame.setVisible(true);		
	}


	//o método "ok" implementa uma "Internal operation". Quando ele é executado, ele dispara um "signal" com o conteúdo "ok", que é percebido pelos agentes
	@INTERNAL_OPERATION void ok(ActionEvent ev){
		signal("ok");
	}

	
	//abaixo, tem-se a implementação da interface gráfica
	class MyFrame extends JFrame {		
		
		private JButton okButton;
		
		public MyFrame(){
			setTitle("Simple GUI ");
			setSize(400,200);
			
			JPanel panel = new JPanel();
			setContentPane(panel);
			
			okButton = new JButton("ok");
			okButton.setSize(80,50);
			
			panel.add(okButton);
			
		}
		

	}
}