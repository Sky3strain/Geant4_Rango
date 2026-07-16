#Python code to plot effective area versus thickness
import matplotlib.pyplot as plt
import numpy as np

#Import text files
data_1keV = np.loadtxt("/home/skyes/Geant4_MSFC/GRango_Data/Plots/ThicknessStudies/EffectiveArea_NaI_1keV_Thick.txt", delimiter=",", dtype=float)
data_5keV = np.loadtxt("/home/skyes/Geant4_MSFC/GRango_Data/Plots/ThicknessStudies/EffectiveArea_NaI_5keV_Thick.txt", delimiter=",", dtype=float)
data_10keV = np.loadtxt("/home/skyes/Geant4_MSFC/GRango_Data/Plots/ThicknessStudies/EffectiveArea_NaI_10keV_Thick.txt", delimiter=",", dtype=float)
data_50keV = np.loadtxt("/home/skyes/Geant4_MSFC/GRango_Data/Plots/ThicknessStudies/EffectiveArea_NaI_50keV_Thick.txt", delimiter=",", dtype=float)
data_100keV = np.loadtxt("/home/skyes/Geant4_MSFC/GRango_Data/Plots/ThicknessStudies/EffectiveArea_NaI_100keV_Thick.txt", delimiter=",", dtype=float)
data_500keV = np.loadtxt("/home/skyes/Geant4_MSFC/GRango_Data/Plots/ThicknessStudies/EffectiveArea_NaI_500keV_Thick.txt", delimiter=",", dtype=float)
data_1000keV = np.loadtxt("/home/skyes/Geant4_MSFC/GRango_Data/Plots/ThicknessStudies/EffectiveArea_NaI_1000keV_Thick.txt", delimiter=",", dtype=float)
data_5000keV = np.loadtxt("/home/skyes/Geant4_MSFC/GRango_Data/Plots/ThicknessStudies/EffectiveArea_NaI_5000keV_Thick.txt", delimiter=",", dtype=float)
data_10000keV = np.loadtxt("/home/skyes/Geant4_MSFC/GRango_Data/Plots/ThicknessStudies/EffectiveArea_NaI_10000keV_Thick.txt", delimiter=",", dtype=float)

#Plot data
plt.ylim(0,130)
plt.plot(data_1keV[:,0], data_1keV[:,1], alpha = 0.6, color='darkblue',  linestyle='--', label="1 keV", linewidth=2)
plt.plot(data_5keV[:,0], data_5keV[:,1], alpha = 0.6, color='royalblue', label="5 keV", linewidth=2)
plt.plot(data_10keV[:,0], data_10keV[:,1], alpha = 0.6, color='deepskyblue', linestyle=':',  label="10 keV", linewidth=3)
plt.plot(data_50keV[:,0], data_50keV[:,1], alpha = 0.6, color='black', label="50 keV", linewidth=2)
plt.plot(data_100keV[:,0], data_100keV[:,1], alpha = 0.6, color='purple',linestyle='--', label="100 keV", linewidth=2)
plt.plot(data_500keV[:,0], data_500keV[:,1], alpha = 0.6, color='fuchsia', label="500 keV", linewidth=2)
plt.plot(data_1000keV[:,0], data_1000keV[:,1], alpha = 0.6, color='darkgreen', label="1000 keV", linewidth=2)
plt.plot(data_5000keV[:,0], data_5000keV[:,1], alpha = 0.6, color='limegreen', label="5000 keV", linewidth=2)
plt.plot(data_10000keV[:,0], data_10000keV[:,1], alpha = 0.6, color='blue', label="10000 keV", linewidth=2)

plt.legend(fontsize=14)
plt.xticks(fontsize=14)
plt.yticks(fontsize=14)
plt.title('Effective Area v.s. Energy For NaI Of Different Thicknesses', fontsize=14)
plt.xlabel('Thickness (cm)', fontsize=14)
plt.ylabel('Effective Area (cm^2)', fontsize=14)
plt.show()
