import matplotlib.pyplot as plt
import numpy as np

data_CdTe = np.loadtxt("/home/skyes/Geant4_MSFC/Geant4_Rango/Plots/EffectiveAreaStudies/EffectiveArea_CdTe.txt", delimiter=",", dtype=float)
data_CsI_Na = np.loadtxt("/home/skyes/Geant4_MSFC/Geant4_Rango/Plots/EffectiveAreaStudies/EffectiveArea_CsI_Na.txt", delimiter=",", dtype=float)
data_CsI = np.loadtxt("/home/skyes/Geant4_MSFC/Geant4_Rango/Plots/EffectiveAreaStudies/EffectiveArea_CsI.txt", delimiter=",", dtype=float)
data_NaI = np.loadtxt("/home/skyes/Geant4_MSFC/Geant4_Rango/Plots/EffectiveAreaStudies/EffectiveArea_NaI.txt", delimiter=",", dtype=float)
data_CsI_Tl = np.loadtxt("/home/skyes/Geant4_MSFC/Geant4_Rango/Plots/EffectiveAreaStudies/EffectiveArea_CsI_Tl.txt", delimiter=",", dtype=float)
data_CeBr3 = np.loadtxt("/home/skyes/Geant4_MSFC/Geant4_Rango/Plots/EffectiveAreaStudies/EffectiveArea_CeBr3.txt", delimiter=",", dtype=float)
data_NaI_Tl = np.loadtxt("/home/skyes/Geant4_MSFC/Geant4_Rango/Plots/EffectiveAreaStudies/EffectiveArea_NaI_Tl.txt", delimiter=",", dtype=float)

plt.plot(data_CsI_Na[:,0], data_CsI_Na[:,1], alpha = 0.6, color='darkblue',  linestyle='--', label="CsI_Na", linewidth=2)
plt.plot(data_CsI_Tl[:,0], data_CsI_Tl[:,1], alpha = 0.6, color='royalblue', label="CsI_Tl", linewidth=2)
plt.plot(data_CsI[:,0], data_CsI[:,1], alpha = 0.6, color='deepskyblue', linestyle=':',  label="CsI", linewidth=3)
plt.plot(data_NaI_Tl[:,0], data_NaI_Tl[:,1], alpha = 0.6, color='black', label="NaI_Tl", linewidth=2)
plt.plot(data_NaI[:,0], data_NaI[:,1], alpha = 0.6, color='purple',linestyle='--', label="NaI", linewidth=2)
plt.plot(data_CdTe[:,0], data_CdTe[:,1], alpha = 0.6, color='fuchsia', label="CdTe", linewidth=2)
plt.plot(data_CeBr3[:,0], data_CeBr3[:,1], alpha = 0.6, color='darkgreen', label="CeBr3", linewidth=2)

plt.xscale('log')
plt.legend(fontsize=14)
plt.xticks(fontsize=14)
plt.yticks(fontsize=14)
plt.title('Effective Area v.s. Energy For Different Scintillators', fontsize=14)
plt.xlabel('Energy (keV)', fontsize=14)
plt.ylabel('Effective Area (cm^2)', fontsize=14)
plt.show()
