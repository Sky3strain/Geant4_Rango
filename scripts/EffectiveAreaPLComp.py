#Python code to plot effective area 
import matplotlib.pyplot as plt
import numpy as np

#Import text files
data_NaI_Tl = np.loadtxt("/home/skyes/Geant4_MSFC/GRango_Data/plots/EffectiveAreaStudies/EffectiveArea_NaI_Tl.txt", delimiter=",", dtype=float)
data_NaI_Tl_O4 = np.loadtxt("/home/skyes/Geant4_MSFC/GRango_Data/plots/EffectiveAreaStudies/EffectiveArea_NaI_Tl_O4.txt", delimiter=",", dtype=float)

#Plot
plt.plot(data_NaI_Tl[:,0], data_NaI_Tl[:,1], alpha = 0.6, color='fuchsia', label="NaI_Tl", linewidth=2)
plt.plot(data_NaI_Tl_O4[:,0], data_NaI_Tl_O4[:,1], alpha = 0.6, color='royalblue', label="NaI_Tl_O4", linewidth=2)

plt.xscale('log')
plt.legend(fontsize=16)
plt.xticks(fontsize=16)
plt.yticks(fontsize=16)
plt.title('Effective Area for different Physics Lists', fontsize=16)
plt.xlabel('Energy (keV)', fontsize=16)
plt.ylabel('Effective Area (cm^2)', fontsize=16)
plt.show()
