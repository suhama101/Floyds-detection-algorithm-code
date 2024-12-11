import pandas as pd
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import matplotlib.patches as mpatches  # For custom legend

# Load preprocessed data
data = pd.read_csv('Graph.csv')  # Replace with your cleaned data file

# Extract columns for plotting
X = data['List Size']
Y = data['Cycle Length']
Z = data['Cycle Start']
colors_steps = data['Steps']  # Color encoded by Steps
colors_list_size = X / X.max()  # Normalize for consistent color mapping
colors_cycle_length = Y / Y.max()
colors_cycle_start = Z / Z.max()

# Create a 3D scatter plot
fig = plt.figure(figsize=(12, 10))
ax = fig.add_subplot(111, projection='3d')

# Plot points with separate color encodings for each factor
sc_steps = ax.scatter(X, Y, Z, c=colors_steps, cmap='viridis', s=70, label='Steps')
sc_list_size = ax.scatter(X, Y, Z, c=colors_list_size, cmap='plasma', s=30, alpha=0.6, label='List Size')
sc_cycle_length = ax.scatter(X, Y, Z, c=colors_cycle_length, cmap='cividis', s=30, alpha=0.6, label='Cycle Length')
sc_cycle_start = ax.scatter(X, Y, Z, c=colors_cycle_start, cmap='cool', s=30, alpha=0.6, label='Cycle Start')

# Set axis labels and title
ax.set_xlabel('List Size', labelpad=15)
ax.set_ylabel('Cycle Length', labelpad=15)
ax.set_zlabel('Cycle Start', labelpad=15)
ax.set_title('3D Scatter Plot of Cycle Detection Steps', pad=20)

# Add color bar for Steps
cbar = plt.colorbar(sc_steps, ax=ax, shrink=0.5, pad=0.1)
cbar.set_label('Steps to Detect Cycle', fontsize=10)

# Add a custom legend explaining the other color encodings
legend_handles = [
    mpatches.Patch(color='purple', label='List Size (Plasma)'),
    mpatches.Patch(color='yellow', label='Cycle Length (Cividis)'),
    mpatches.Patch(color='cyan', label='Cycle Start (Cool)'),
]
ax.legend(handles=legend_handles, loc='upper left', bbox_to_anchor=(1.05, 1), fontsize=9, title='Factors')

# Add grid for better readability
ax.grid(True)

# Save and show the plot
plt.savefig('enhanced_3d_scatter_plot.png', dpi=300, bbox_inches='tight')
plt.show()
