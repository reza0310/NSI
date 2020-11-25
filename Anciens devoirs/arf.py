t=[0]
for i in input().split():
    t.append(int(i))
t.sort()
i=t.index(0)
print(t[i-1] if i==len(t)-1 or t[i-1] < 0 and t[i]-t[i-1]<t[i+1]-t[i] else t[i+1] if t[i]-t[i-1]>=t[i+1]-t[i] else 0)