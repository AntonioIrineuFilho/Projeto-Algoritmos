import matplotlib.pyplot as plt

# Medir tempos de execução para diferentes tamanhos de entrada
entradas = [100, 1000, 10000, 100000, 1000000]
tempos = [0.000027, 0.000445, 0.0454315, 4.613546, 464.393]

# Criar o gráfico
plt.figure(figsize=(8, 5))
plt.plot(entradas, tempos, marker='o', label="Tempo de execução")
plt.xscale("log")  # Escala logarítmica para o eixo X, se necessário
plt.yscale("log")  # Escala logarítmica para o eixo Y
plt.title("Tempos de execução vs Tamanho de entrada - Insertion Sort", fontsize=14)
plt.xlabel("Tamanho da entrada (n)", fontsize=12)
plt.ylabel("Tempo de execução (s)", fontsize=12)
plt.grid(True, which="both", linestyle="--", linewidth=0.5)  # Grade em escala logarítmica
plt.legend()
plt.show()
