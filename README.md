# Kilobots-Positioning-and-Navigation

This repository provides an example of using the Augmented Reality for Kilobots (ARK) System to provide the Kilobot robots with positioning information. In this example, the Kilobot use the positioning information to navigate between two locations of interast

The repository provides:

1. The ARK experiment which uses ARK's tracking functionalities to create a grid-based positioning system and periodically send IR message to the Kilobots on the arena to provide positioning information. For getting started with ARK please visit [link](https://www.giovannireina.com/kilowiki/index.php?title=Getting_started_on_ARK).

2. The .c code that is compiled and uploaded on the Kilobot to parse the positioning information received from the ARK system and use it to navigate between to locations of interest. To compile the provided Kilobot code please visit [link](https://www.giovannireina.com/kilowiki/index.php?title=Getting_Started:_How_to_work_with_kilobots).

# Acknowledgement

Part of the source code in this repository is developed within the frame and for the purpose of the OpenSwarm project. This project has received funding from the European Unioan's Horizon Europe Framework Programme under Grant Agreement No. 101093046.

![OpenSwarm - Funded by the European Union](logos/ack.png)
