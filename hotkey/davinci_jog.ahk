#Requires AutoHotkey v2.0
#SingleInstance Force
SetTitleMatchMode 2
DetectHiddenWindows false

; ──────────────────────────────
; CONFIG
; ──────────────────────────────
poll_interval := 25       ; ms entre lecturas del ratón
dx_threshold := 2         ; píxeles mínimos para detectar movimiento
repeat_cooldown := 35     ; ms entre comandos enviados

; ──────────────────────────────
; GLOBAL VARIABLES
; ──────────────────────────────
global jog_mode := false
global shuttle_mode := false
global scroll_mode := false
global prevX := 0
global lastSend := 0

; ──────────────────────────────
; TRIGGER KEYS
; ──────────────────────────────
F1:: {
    global jog_mode, shuttle_mode, scroll_mode
    jog_mode := !jog_mode
    shuttle_mode := false
    scroll_mode := false
}

F2:: {
    global jog_mode, shuttle_mode, scroll_mode
    shuttle_mode := !shuttle_mode
    jog_mode := false
    scroll_mode := false
}

F3:: {
    global jog_mode, shuttle_mode, scroll_mode
    scroll_mode := !scroll_mode
    jog_mode := false
    shuttle_mode := false
}

; ──────────────────────────────
; ACTIVE WINDOW DETECTION
; ──────────────────────────────
SetTimer(CheckResolveActive, 250)

CheckResolveActive(*) {
    global prevX
    static active := false

    if WinActive("ahk_exe Resolve.exe") {
        if !active {
            prevX := GetMouseX()
            SetTimer(PollMouse, poll_interval)
            active := true
        }
    } else {
        if active {
            SetTimer(PollMouse, false)
            active := false
        }
    }
}

; ──────────────────────────────
; MOUSE DETECTION POLL
; ──────────────────────────────
PollMouse(*) {
    global prevX, lastSend, dx_threshold, repeat_cooldown
    global jog_mode, shuttle_mode, scroll_mode

    x := GetMouseX()
    dx := x - prevX
    absDx := Abs(dx)

    if absDx < dx_threshold
        return

    now := A_TickCount
    if (now - lastSend < repeat_cooldown) {
        prevX := x
        return
    }

    direction := (dx < 0) ? "L" : "R"

    ; ── JOG ULTRASENSIBLE ──
    if jog_mode {
    steps := Ceil(absDx * 1)  ; Jog sensitivity
    Loop steps {
        if direction = "L"
            SendInput("^+{Left}")
        else
            SendInput("^+{Right}")
        }
    }
    else if shuttle_mode {
        if direction = "L"
            SendInput "j"
        else
            SendInput "l"
    }
    else if scroll_mode {
        scroll_sensitivity := 3  ; Scroll sensitivity
        steps := Ceil(absDx * scroll_sensitivity)
        Loop steps {
            if direction = "L"
                SendInput "^+!{Left}"
            else
                SendInput "^+!{Right}"
        }
    }

    lastSend := now
    prevX := x
}

; ──────────────────────────────
; MOUSE POSITION DETECTION
; ──────────────────────────────
GetMouseX() {
    local x := 0, y := 0
    MouseGetPos &x, &y
    return x
}
