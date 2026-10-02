# companion — PC-side daemon

Watches a Claude Code usage snapshot file and pushes updates to the ESP32 over BLE.

## Planned flow

1. A Claude Code `Stop` hook writes session stats to a local JSON file (path TBD, e.g. `~/.claude/usage_snapshot.json`)
2. This daemon watches that file for changes
3. On change: parse the JSON, connect to the ESP32 BLE service, write updated characteristic values

## Status

Not yet implemented. Language and packaging TBD (Python preferred for portability).

## Open questions

- Exact fields available in the Claude Code hook payload / session transcript
- BLE library for desktop Python: `bleak` (cross-platform, async) is the candidate
- Auto-reconnect behaviour when ESP32 goes out of range
