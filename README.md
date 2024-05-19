# Automatic Coil Winding Machine - INCOMPLETE WIP
### Designed by Hyperspace Pirate
### Modified by Serialbocks

This repo contains my iteration of Hyperspace Pirate's Automatic Coil winding machine. I'm creating this repo to document the hardware, software, schematics, and 3d files used for this project to be in one central location.

The motivation for this project is to create my own electronic chess pieces by winding wire around a cylindrical ferrite core. This repo may contain some files related to chess designing around that goal.

### Original Design Documents by Hyperspace Pirate:
- [Youtube Video]
- [Thingiverse Post]

There are a few notable changes I've made and plan on making from the original design:

 - Use a Raspberry Pi Pico as the microcontroller
 - Adapt my own firmware from the original specifically for 38 AWG copper enameled wire (TODO)
 - Change interface from 5 push buttons to one [360 degree rotary encoder](https://www.amazon.com/gp/product/B09KNC1J6H) (TODO)

In the original [Thingiverse Post] post, there were a couple of missing 3d files used in Hyperspace Pirate's final iteration, one of which I got from the comments on that page (Stepper_Block_V2.STL) and another I created in blender based on his original [Youtube Video] (New_Wire_Follower.blend/New_Wire_Follower.stl). I moved all 3d models that weren't used in his final iteration (or that I didn't end up using) to a folder named `old` within the `3d-printed-parts` foler.

   [Thingiverse Post]: <https://www.thingiverse.com/thing:5261994>
   [Youtube Video]: <https://www.youtube.com/watch?v=GJcQfJ6JTZg>
