import matplotlib.pyplot as plt


def make_plot():
    x = [1, 1, 2, 2, 4]
    y = [1, 2, 1, 4, 1]
    plt.plot(x, y, color='purple', linestyle='dashed', linewidth=3,
             marker='o', markerfacecolor='green', markersize=12)
    plt.xlabel('X Axis')
    plt.ylabel('Y Axis')
    plt.title('Abhinav Kumar')
    plt.show()


def make_bar():
    left = [1, 2, 3, 4, 5]
    height = [10, 24, 36, 40, 5]
    tick_label = ['JAVA', 'C', 'C++', 'Python', 'Pascal']
    plt.bar(left, height, tick_label=tick_label,
            width=0.8, color=['purple', 'green'])
    plt.xlabel('X Axis')
    plt.ylabel('Y Axis')
    plt.title('Abhinav Kumar')
    plt.show()


def make_scatter():
    x = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    y = [2, 4, 5, 7, 6, 8, 9, 11, 12, 12]
    plt.scatter(x, y, label="Random Stars", color="purple",
                marker="*", s=30)
    plt.xlabel('X Axis')
    plt.ylabel('Y Axis')
    plt.title('Abhinav Kumar')
    plt.legend()
    plt.show()


def make_pie():
    activities = ['Sleeping', 'Programming', 'Gaming', 'Reddit']
    slices = [6, 7, 8, 3]
    colors = ['orange', 'green', 'purple', 'red']
    plt.pie(slices, labels=activities, colors=colors,
            startangle=90, shadow=True, explode=(0, 0, 0.1, 0),
            radius=1.2, autopct='%1.1f%%')
    plt.legend()
    plt.show()


if __name__ == "__main__":
    make_pie()



