# Mini-Midi-Controller
This poject has the goal of teaching you how to build a sixteen-button mini midi controller. 
These instructions will follow the steps I took in completing this project. 
Of course, these instructions may be modified to fit your needs, but the goal is to provide
a comprehensive list of instructions and resources to make your journey to building your own
midi-controller easier. Also, this project was completed on a MacBook Pro with OS X Yosemite.

I chose to use a digital Serial - MIDI Converter, but you may choose to use a MIDI-USB cable.

Arduino Midi-Controller Project:

HARDWARE:
  The instructions used to build the actual device were found at:
    https://learn.adafruit.com/trellis-3d-printed-enclosure
    
  Parts needed:
    - Arduino Uno
    - 4 jumper cables
    - 1 Adafruit 4x4 Trellis (https://www.adafruit.com/product/1616)
    - 1 Elastomer 4x4 Button Keypad (https://www.adafruit.com/product/1611)
    - 16 3mm LED lights
    - Soldering Iron
    - Solder Suitable for Electrical Parts
    
    Assembly of the Trellis and Arduino may be found at:
      https://learn.adafruit.com/trellis-3d-printed-enclosure/assembly
    
    
Mini-Midi Controller Case:
  The 3-D printed case was found at:
    https://learn.adafruit.com/trellis-3d-printed-enclosure/3d-printing
    
    
SOFTWARE:
  DAW(Digital Audio Workstation):
    A DAW is a software program that allows for the playing, recording, manipulation of sounds and music. 
    There are many programs to choose from. Find one that works best for you. For this project, I have
    used GarageBand. Why did I choose this one? Simply because it was a DAW already installed on my computer.
    
  MIDI-Serial Bridge:
    Your DAW needs a MIDI signal to play a MIDI note. Your Arduino sends out serial data,
    but your DAW needs MIDI data to properly function. To convert serial to MIDI data, we
    need a converter, whether via software or hardware. To do this, I used the 
    the Hairless MIDI <-> Serial Bridge which can be downloaded here:
      http://projectgus.github.io/hairless-midiserial/
      
  MIDI Port:
    You will need a MIDI port for which to send out the MIDI signal from. On a Mac, I downloaded 
    the ipMIDI port from here:
      http://nerds.de/en/ipmidi_osx.html
    
  Setting up ipMIDI Port:
    This port is considered an external device by your computer and it is import to make sure your
    computer and your MIDI-Serial Bridge recognize it.
    You can do this by opening your Mac's Audio MIDI Setup. You can search for it via Spotlight Search.
    Type in "Audio MIDI Setup" and the program should open and you will see the ipMIDI listed.
  
  Set-up Software:
      - Open the Hairless MIDI <-> Serial Bridge.
      - Set the Serial Port to your Arduino port option
      - Set the MIDI out port to "ipMIDI port1"
      -Plug in your Arduino and run the Arduino MIDI program, you should see green lights
        flashing on the Hairless program. This means the signals are being detected.
      - Open your DAW and set up an instrument. 
      - Push a button on your MIDI controller and a note should be played!
  
    
  
