import matplotlib.pyplot as plt
import numpy as np
from scipy.interpolate import PchipInterpolator

entradas = [100, 1000, 10000, 100000, 1000000]
tempos = [0.00005, 0.0006, 0.0026, 0.0175, 0.129]

entradas = np.array(entradas)
tempos = np.array(tempos)

interpolador = PchipInterpolator(entradas, tempos)

x_novo = np.logspace(np.log10(entradas.min()), np.log10(entradas.max()), 500)
y_suave = interpolador(x_novo)

# Criar o gráfico
plt.figure(figsize=(8, 5))
plt.plot(x_novo, y_suave, label="Tempo de execução (Curva Suavizada)", color="blue")
plt.scatter(entradas, tempos, color="red", label="Tamanho de entrada")
plt.xscale("log")
plt.yscale("linear")
plt.title("Tempos de execução vs Tamanho de entrada - Quick Sort", fontsize=14)
plt.xlabel("Tamanho da entrada (n)", fontsize=12)
plt.ylabel("Tempo de execução (s)", fontsize=12)
plt.grid(True, which="both", linestyle="--", linewidth=0.5)
plt.legend()
plt.show()