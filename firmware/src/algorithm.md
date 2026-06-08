### Algorithm 

```mermaid
```
```
flowchart TD; 
  A([Start main]) --> B[setup variable]
  B --> C[/keypad return num/]
  C --> D{num = #$#}
  D -->|yes| C 
  D -->|no| E{if # button} 
  E -->|yes| E0[state = !state] --> C 
  E -->|no| E1{if * button} -->|yes| id1{ have num-1 && num-2 && ope } 
  id1 -->|yes| id2a[/Led out result & lock/] --> A 
  id1 -->|no| id2b[/Led out errol & lock/] --> C 
  E1 -->|no| E2{if ABCD button} 
  E2 -->|yes| id3a[set operator] --> C 
  E2 -->|no| E3{num == 0123456789}
  E3 -->|yes| id4{state == 0}
  id4 -->|yes| id4a[update num-1] --> C 
  id4 -->|no| id5{state == 1} -->|yes| id5a[update num-2] --> C 
  id5 -->|no| C 
  E3 -->|no| A
```
```  

