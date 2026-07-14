#Python code to plot real vs sim data
import matplotlib.pyplot as plt
import numpy as np

energy = [22.10, 25.00, 30.85, 81.00]

real_8255 = [0.587442838, 0.71910828, 0.785248714, 0.948106592]
real_8255_err = [0.031109965, 0.054263819, 0.035564707, 0.056620779]

sim_8255 = [0.575872, 0.7576974, 0.803956, 0.958157]
sim_8255_err = [0.002399733, 0.002601872, 0.002835412, 0.003095411]

real_16510 = [0.339883822, 0.520382166, 0.673756432, 0.934081346]
real_16510_err = [0.064943656, 0.08289779, 0.043328381, 0.057691995]

sim_16510 = [0.32883, 0.461149, 0.646882, 0.922563,]
sim_16510_err = [0.001813367, 0.002147438, 0.002543388, 0.003037372]
plt.errorbar(energy, real_8255, yerr = real_8255_err, alpha = 0.75, label = "0.8255 mm real", marker = 'o', color='fuchsia')
plt.errorbar(energy, sim_8255, yerr = sim_8255_err, alpha = 0.75, label = "0.8255 mm sim", marker = 'o', color='coral')
plt.errorbar(energy, real_16510, yerr = real_16510_err, alpha = 0.75, label = "1.651 mm real", marker = 'o', color='deepskyblue')
plt.errorbar(energy, sim_16510, yerr = sim_16510_err, alpha = 0.75, label = "1.651 mm sim", marker = 'o', color='purple')
plt.legend(fontsize=20)
plt.xticks(fontsize=16)
plt.yticks(fontsize=16)
plt.xlabel("Energy (keV)", fontsize=16)
plt.ylabel("Transmission", fontsize=16)
plt.legend()
plt.title("Transmission comparisson study for 0.8255 mm and 1.651 mm Al", fontsize=16)
plt.show()