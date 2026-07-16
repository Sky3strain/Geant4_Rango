#Python code to create a histogram of edep vs count data. 
import matplotlib.pyplot as plt
import numpy as np

#Import text file
dataAl1MM = np.loadtxt("/home/skyes/Geant4_MSFC/GRango_Data/Plots/TransmissionStudies/Transmission_1-10000keV_Al1MM.txt", delimiter=',', dtype=float)
dataAl1MM_O4 = np.loadtxt("/home/skyes/Geant4_MSFC/GRango_Data/Plots/TransmissionStudies/Transmission_1-10000keV_Al1MM_O4.txt", delimiter=',', dtype=float)

#plot
plt.plot(dataAl1MM[:,0], dataAl1MM[:,1], color='limegreen', label="Al 1mm")
plt.plot(dataAl1MM_O4[:,0], dataAl1MM_O4[:,1], color='black', label="Al 2mm")

plt.legend(fontsize=16)
plt.xscale("log")
plt.ylim(0,1.05)
plt.xticks(fontsize=16)
plt.yticks(fontsize=16)
plt.xlabel("Energy (keV)", fontsize=16)
plt.ylabel("Transmission", fontsize=16)
plt.title("Physics List Comparison for Transmission", fontsize=16)
plt.show()