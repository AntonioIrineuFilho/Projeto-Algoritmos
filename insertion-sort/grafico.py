import matplotlib.pyplot as plt
from scipy.interpolate import make_interp_spline  # Para suavização
import numpy as np

# Medir tempos de execução para diferentes tamanhos de entrada
entradas = [100, 1000, 10000, 100000, 1000000]
tempos = [0.000027, 0.000445, 0.0454315, 4.613546, 464.393]

# Converter para numpy arrays para manipulação
entradas = np.array(entradas)
tempos = np.array(tempos)

# Criar uma interpolação spline
x_novo = np.logspace(np.log10(entradas.min()), np.log10(entradas.max()), 500)
spline = make_interp_spline(entradas, tempos)
y_suave = spline(x_novo)

# Criar o gráfico
plt.figure(figsize=(8, 5))
plt.plot(x_novo, y_suave, label="Tempo de execução", color="blue")
plt.scatter(entradas, tempos, color="red", label="Pontos originais")  # Mostrar os pontos reais
plt.xscale("log")  # Escala logarítmica para o eixo X
plt.yscale("linear")  # Escala logarítmica para o eixo Y
plt.title("Tempos de execução vs Tamanho de entrada - Insertion Sort", fontsize=14)
plt.xlabel("Tamanho da entrada (n)", fontsize=12)
plt.ylabel("Tempo de execução (s)", fontsize=12)
plt.grid(True, which="both", linestyle="--", linewidth=0.5)
plt.legend()
plt.show()

