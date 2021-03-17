import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv('mpi_pp_results.csv')

message_sizes = df["message-size"].tolist()

single_node_std_shm = df["1-node-std-shm"].tolist()
single_node_std_net = df["1-node-std-net"].tolist()
two_node_same_host_std = df["2-node-std-samehost"].tolist()
two_node_diff_host_std = df["2-node-std-diffhost"].tolist()

single_node_buf_shm = df["1-node-buf-shm"].tolist()
single_node_buf_net = df["1-node-buf-net"].tolist()
two_node_same_host_buf = df["2-node-buf-samehost"].tolist()
two_node_diff_host_buf = df["2-node-buf-diffhost"].tolist()

# plt.plot(message_sizes, single_node_std_shm, label = "1 node, standard communication, shared memory")
# plt.plot(message_sizes, single_node_std_net, label = "1 node, standard communication, net")
# plt.plot(message_sizes, two_node_same_host_std, label = "2 nodes same host, standard communication")
# plt.plot(message_sizes, two_node_diff_host_std, label = "2 nodes diff host, standard communication")

plt.plot(message_sizes, single_node_buf_shm, label = "1 node, buffered communication, shared memory")
plt.plot(message_sizes, single_node_buf_net, label = "1 node, buffered communication, net")
plt.plot(message_sizes, two_node_same_host_buf, label = "2 nodes same host, buffered communication")
plt.plot(message_sizes, two_node_diff_host_buf, label = "2 nodes diff host, buffered communication")

plt.xlabel('Message size [B]')
plt.ylabel('Throughput [Mbit/s]')
plt.title('MPI PP communication throughput, depending on message size and nodes configuration')
# show a legend on the plot
plt.legend()
# Display a figure.
plt.show()
