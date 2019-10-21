library(plotly)

options(scipen = 999)

data10tcp <-
  read.csv("/Users/reubenfresquez/Documents/CS585/lab2/data/tcp_latency10.csv")
names(data10tcp)[1] <- "d"
data100tcp <-
  read.csv("/Users/reubenfresquez/Documents/CS585/lab2/data/tcp_latency100.csv")
names(data100tcp)[1] <- "d"
data1000tcp <-
  read.csv("/Users/reubenfresquez/Documents/CS585/lab2/data/tcp_latency1000.csv")
names(data1000tcp)[1] <- "d"
data10000tcp <-
  read.csv("/Users/reubenfresquez/Documents/CS585/lab2/data/tcp_latency10000.csv")
names(data10000tcp)[1] <- "d"

data10udp <-
  read.csv("/Users/reubenfresquez/Documents/CS585/lab2/data/udp_latency10.csv")
names(data10udp)[1] <- "d"
data100udp <-
  read.csv("/Users/reubenfresquez/Documents/CS585/lab2/data/udp_latency100.csv")
names(data100udp)[1] <- "d"
data1000udp <-
  read.csv("/Users/reubenfresquez/Documents/CS585/lab2/data/udp_latency1000.csv")
names(data1000udp)[1] <- "d"
data10000udp <-
  read.csv("/Users/reubenfresquez/Documents/CS585/lab2/data/udp_latency10000.csv")
names(data10000udp)[1] <- "d"

numClients <- c(10, 100, 1000, 10000)

avgDataTcp <-
  c(mean(data10tcp$d), mean(data100tcp$d), mean(data1000tcp$d), mean(data10000tcp$d))

avgDataUcp <-
  c(mean(data10udp$d), mean(data100udp$d), mean(data1000udp$d), mean(data10000udp$d))

graphingData <-
  data.frame("x" = numClients, "tcp" = avgDataTcp, "udp" = avgDataUcp)


p <- plot_ly(graphingData) %>%
  add_trace(x = ~ x, y = ~ tcp, name = "TCP", type = "scatter", mode = "lines+markers") %>%
  add_trace(x = ~ x, y = ~ udp, name = "UDP", type = "scatter", mode = "lines+markers") %>%
  layout(
    title = "Average Latency in Seconds Per Number of Clients",
    xaxis = list(title = "Number of Clients"),
    yaxis = list(title = "Average Latency", exponentformat = "none")
  )

p