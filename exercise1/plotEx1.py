import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

# Read the data from the CSV files
headers = ['array_size', 'time']
df = pd.read_csv('dataEx1.csv', names=headers)
df_vectorized = pd.read_csv('dataEx1_vectorized.csv', names=headers)

# Define a custom function for formatting the x-axis labels as powers of 2
def format_x_labels(value, _):
    if value == 1:
        return '2^0'
    return f'2^{int(np.log2(value))}'

# Plot the data
plt.figure(figsize=(13, 8))
plt.plot(df['array_size'], df['time'], marker='o', label='Non-vectorized Data', color='c')
plt.plot(df_vectorized['array_size'], df_vectorized['time'], marker='o', label='Vectorized Data', color='y')

# Customize the plot
plt.xlabel('Array Size')
plt.ylabel('Time (s)')
plt.title('Sequential vs vectorized array addition time')
plt.xscale('log')
plt.yscale('log')
plt.xticks(df['array_size'], labels=df['array_size'].astype(str), rotation=45)
plt.gca().xaxis.set_major_formatter(plt.FuncFormatter(format_x_labels))

# Add legend and grid
plt.legend()
plt.grid(True, which='both', linestyle='--', linewidth=0.5)

# Show the plot
plt.savefig("dataEX1.png")