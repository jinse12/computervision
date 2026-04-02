# 과제 1
용어 조사하기

---

## 1. API (Application Programming Interface)

응용 프로그램 프로그래밍 인터페이스로, 소프트웨어 간에 서로 통신할 수 있도록 정의된 규칙과 프로토콜의 집합이다.
개발자가 특정 기능을 직접 구현하지 않고, 이미 만들어진 기능을 호출하여 사용할 수 있게 해주는 중간 다리 역할을 한다.
예를 들어 OpenCV API, Windows API, REST API 등이 있다.

---

## 2. V4L (Video4Linux)

Linux 커널에 포함된 비디오 장치 드라이버 프레임워크로, 웹캠·캡처 카드 등의 비디오 입력 장치를 제어하기 위한 API이다.
현재는 개선된 버전인 V4L2(Video4Linux2)가 표준으로 사용되며,
Linux 환경에서 OpenCV의 `VideoCapture` 사용 시 내부적으로 V4L2가 활용된다.

---

## 3. FFMPEG

오디오 및 비디오의 녹화, 변환, 스트리밍을 처리하는 오픈소스 멀티미디어 프레임워크이다.
Windows, Linux, macOS를 모두 지원하는 크로스 플랫폼 환경에서 동작하며,
MP4, AVI, MKV, H.264, H.265 등 수백 가지의 코덱과 포맷을 지원한다.
OpenCV 빌드 시 FFMPEG를 백엔드로 사용하여 동영상 파일 읽기/쓰기를 지원한다.

---

## 4. DirectShow

Microsoft가 개발한 Windows 전용 멀티미디어 스트리밍 프레임워크이다.
COM(Component Object Model) 기반으로 동작하며, 비디오/오디오 캡처, 재생, 인코딩 등을
필터 그래프(Filter Graph) 방식으로 처리한다.
Windows에서 OpenCV `VideoCapture` 사용 시 DirectShow를 백엔드로 사용할 수 있으며,
최신 Windows에서는 MSMF로 대체되는 추세이다.

---

## 5. MSMF (Microsoft Media Foundation)

DirectShow의 후속으로 Microsoft가 개발한 Windows 최신 멀티미디어 API이다.
Windows Vista 이상에서 지원되며, 하드웨어(GPU) 가속 인코딩/디코딩을 지원하여
DirectShow보다 향상된 성능을 제공한다.
Windows에서 OpenCV `VideoCapture`의 기본 백엔드로 사용된다(`CAP_MSMF`).

---

## 6. GStreamer

플러그인 기반의 오픈소스 멀티미디어 프레임워크로, 파이프라인(Pipeline) 방식으로 미디어 데이터를 처리한다.
Linux, Windows, macOS를 모두 지원하는 크로스 플랫폼 환경에서 동작하며,
Linux 및 라즈베리파이, Jetson 등 임베디드 시스템에서 특히 널리 사용된다.
OpenCV에서 `VideoCapture("gst-pipeline-string")` 형태로 GStreamer 파이프라인을 직접 사용할 수 있다.

---
