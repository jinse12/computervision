# 실습과제 3
코드 5-6에서 α가 너무 크면 어떻게 되는가, α가 너무 작으면 어떻게 되는가? 실행결과를 첨부하고 이유를 설명하라.

---

## α가 너무 클 때 (alpha = 10.f)

```cpp
float alpha = 10.f;
```

### 실행 결과

<img width="1267" height="672" alt="image" src="https://github.com/user-attachments/assets/def6e64d-eb69-4104-97b5-cc691ae04d04" />


### 이유
dst = saturate(src + (src - 128) * alpha)에서 alpha = 10이면, 128보다 밝은 픽셀은 결과값이 255를 크게 초과하여 255로 포화되고, 128보다 어두운 픽셀은 결과값이 0을 크게 밑돌아 0으로 포화된다. alpha가 클수록 포화되는 픽셀이 많아져 중간 픽셀값이 거의 사라지므로, 영상이 흑백 이진 영상처럼 보이게 된다.

---

## α가 너무 작을 때 (alpha = -1.f)

```cpp
float alpha = -1.f;
```

### 실행 결과

<img width="1272" height="671" alt="image" src="https://github.com/user-attachments/assets/2bb33ea6-f8ff-44df-84f9-03f56a7a4302" />


### 이유
수식에 alpha = -1을 대입하면 dst = src + (src - 128) * (-1) = src - src + 128 = 128이 된다. 픽셀값에 관계없이 계산 결과가 항상 128이므로, 모든 픽셀이 128으로 수렴하여 명암비가 완전히 사라진 단색 회색 영상이 된다.
