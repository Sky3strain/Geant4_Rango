#Python code to create a histogram of edep vs count data. 
import matplotlib.pyplot as plt
import numpy as np
import seaborn as sns

#Import text file
data = np.loadtxt("/home/skyes/Geant4_MSFC/Rango/build/output.txt")

#plot
sns.histplot(data, bins = 100, stat="count")
plt.gca().set_yscale('log') 
plt.xlabel("Edep")
plt.ylabel("Count")
plt.title("edep vs count")
plt.show()